/* 
 * File:   atomic_cells.hpp
 * Author: xetql
 *
 * Created on April 10, 2017, 6:25 PM
 */

#ifndef ATOMIC_CELLS_HPP
#define ATOMIC_CELLS_HPP

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <memory>
#include <random> 
#include <set>
#include <type_traits>
#include <vector>

// Structure that defines an atomic subcell of the simulation.
// Similar to overdecomposition method (cf. Charm++)
namespace liblj {

    const double ATOMIC_CELL_WIDTH = 0.001;
    const double ATOMIC_CELL_HEIGHT = 0.001;

    struct work_unit_t;
    struct atomic_cell_t;
    class work_unit_builder_t;

    // Type used to discuss with the API. Actually, we work with objects
    // However, it is possible that in the future we will work with smart-ptr.
    using work_unit_return_t = work_unit_t;

    template<class T>
    using ptr_t = std::shared_ptr<T>;

    struct work_unit_t {
        float x, y, vx, vy;

        virtual ~work_unit_t() {
        }

        bool operator==(const work_unit_t& right) const {
            return this->x == right.x && this->y == right.y && this->vx == right.vx && this->vy == right.vy && this->_id == right._id;
        }

        friend std::ostream& operator<<(std::ostream& os, const work_unit_t& obj) {
            return (os << "{" << obj.x << "," << obj.y << "}");
        }

        bool operator<(const work_unit_t& right) const {
            return (this->norm() * this->vnorm()) < (right.norm() * right.vnorm());
        }

        bool operator>(const work_unit_t& right) const {
            return (this->norm() * this->vnorm()) > (right.norm() * right.vnorm());
        }

        friend work_unit_builder_t;
        friend atomic_cell_t;

        //work_unit_t(const work_unit_t& that) = default;

        int get_dimension(int dim) {
            switch (dim) {
                case 0: return this->x;
                case 1: return this->y;
            }
        }

     work_unit_t(float x, float y, float vx, float vy) :
        x(x), y(y), vx(vx), vy(vy) {
            static int id = 0;
            _id = id++;
        }

    private:

        int _id;

        float norm() const {
            return x * x + y*y;
        }

        float vnorm() const {
            return vx * vx + vy*vy;
        }
    };

    ptr_t<std::vector<float>> serialize_work_units(std::vector<work_unit_t> wu_array) {
        ptr_t<std::vector<float>> v(new std::vector<float>());
        for (auto const &wu : wu_array){
            v->push_back(wu.x);
            v->push_back(wu.y);
            v->push_back(wu.vx);
            v->push_back(wu.vy);
        }
        return v;
    }
    
    ptr_t<std::vector<float>> serialize_work_units_position(std::vector<work_unit_t> wu_array) {
        ptr_t<std::vector<float>> v(new std::vector<float>());
        for (auto const &wu : wu_array){
            v->push_back(wu.x);
            v->push_back(wu.y);
        }
        return v;
    }

    class work_unit_builder_t {
    private:
        float posy, posx, velx, vely;
        bool setposx = false, setposy = false, setvelx = false, setvely = false;
        // work_unit_builder_t* instance;

        work_unit_builder_t() {
        } // private constructor

    public:

        static work_unit_builder_t& get_instance() {
            static work_unit_builder_t instance;
            return instance;
        }

        work_unit_builder_t with_posx(float posx) {
            this->setposx = true;
            this->posx = posx;
            return *this;
        }

        work_unit_builder_t with_posy(float posy) {
            this->setposy = true;
            this->posy = posy;
            return *this;
        }

        work_unit_builder_t with_velx(float velx) {
            this->setvelx = true;
            this->velx = velx;
            return *this;
        }

        work_unit_builder_t with_vely(float vely) {
            this->setvely = true;
            this->vely = vely;
            return *this;
        }

        work_unit_return_t build() {
            if (!(setposx && setposy && setvelx && setvely))
                throw std::runtime_error("");
            work_unit_t wu(posx, posy, velx, vely);
            setposx = false;
            setposy = false;
            setvelx = false;
            setvely = false;
            return wu;
        }
    };

    struct atomic_cell_t {
        const float x, y, width, height;
        std::vector<work_unit_return_t> work_units;
        bool is_bordering_cell;

        /**
         * Constructor of a non empty atomic cell via deserialization.
         * @param data
         */
        atomic_cell_t(std::vector<float> data) : x((float) data[0]), y((float) data[1]), width((float) data[2]), height((float) data[3]) {
            auto wu_builder = work_unit_builder_t::get_instance();
            for (int i = 4; i < data.size(); i += 4) {
                auto current_wu = wu_builder.with_posx(data[i]).with_posy(data[i + 1]).with_velx(data[i + 2]).with_vely(data[i + 3]).build(); //((float) data[i], (float) data[i + 1], (float) data[i + 2], (float) data[i + 3]);
                work_units.push_back(current_wu);
            }
        }

        /**
         * Constructor of an empty atomic cell.
         * @param x x position of this cell
         * @param y y position of this cell
         */
        atomic_cell_t(const float x, const float y) :
        x(x), y(y), width(ATOMIC_CELL_WIDTH), height(ATOMIC_CELL_HEIGHT), is_bordering_cell(false) {
        }

        /**
         * Constructor of an empty atomic cell.
         * @param x x position of this cell
         * @param y y position of this cell
         */
        atomic_cell_t(const float x, const float y, bool is_bordering_cell) :
        x(x), y(y), width(ATOMIC_CELL_WIDTH), height(ATOMIC_CELL_HEIGHT), is_bordering_cell(is_bordering_cell) {
        }

        /**
         * Get the memory size of this whole cell
         * @return the memory size of this whole cell
         */
        int get_memory_size() {
            int memory_size = 0;
            memory_size += 4 * sizeof (float);
            memory_size += work_units.size() * sizeof (float) * 4;
            return memory_size;
        }

        /**
         * Compute the number of work unit inside this cell
         * @return the number of work unit
         */
        int number_of_work_unit() {
            return this->work_units.size();
        }

        /**
         * Get an iterator to the first work unit
         * @return the iterator to the first work unit
         */
        std::vector<work_unit_return_t>::iterator get_first_work_unit() {
            return this->work_units.begin();
        }

        /**
         * Get an iterator to the first work unit
         * @return the iterator to the first work unit
         */
        std::vector<work_unit_return_t>::iterator get_last_work_unit() {
            return this->work_units.end();
        }

        /**
         * Overload of the iostream print operator
         * @return 
         */
        friend std::ostream& operator<<(std::ostream& os, const atomic_cell_t& obj) {
            os << "{ " << obj.x << ", " << obj.y << ", " << obj.width << ", " << obj.height;
            for (auto const &wu : obj.work_units) {
                os << ", " << wu;
            }
            os << " }";

            return os;
        }

        /**
         * Serialize the object into a vector of float and then produce an unique_ptr
         * on the newly created vector
         * @return the serialized object as a float vector
         */
        ptr_t<std::vector<float>> serialize() {
            ptr_t<std::vector<float>> v(new std::vector<float>());
            v->push_back(x);
            v->push_back(y);
            v->push_back(width);
            v->push_back(height);
            for (auto &wu : work_units) {
                v->push_back(wu.x);
                v->push_back(wu.y);
                v->push_back(wu.vx);
                v->push_back(wu.vy);
            }
            return v;
        }

        /**
         * Adds a work unit to the atomic cell
         * @param wu the work unit
         */
        void add_work_unit(work_unit_return_t& wu) {
            if (this->contains(this->x, this->y, this->width, this->height, wu.x, wu.y))
                this->work_units.push_back(wu);
        }

        /**
         * Does this work unit belongs to this atomic cell ? The work unit
         * may not be inside the structure yet. 
         * @param wu the work unit
         * @return true if physically contained false otherwise
         */
        bool contains(work_unit_return_t& wu) {
            return this->contains(this->x, this->y, this->width, this->height, wu.x, wu.y);
        }

        /**
         * Does this work unit already inside this atomic cell ?
         * @param wu
         * @return true if contained in this structure false otherwise
         */
        bool is_attributed(work_unit_return_t& wu) {
            return (contains(wu) && (std::find(this->work_units.begin(), this->work_units.end(), wu) != this->work_units.end()));
        }

        /**
         * Parse the work units and return the work units which are not in the cell
         * anymore..
         * @return The work units that moved out the cell.
         */
        ptr_t<std::vector<work_unit_return_t>> scan() {
            ptr_t<std::vector < work_unit_return_t >> v(new std::vector<work_unit_return_t>());
            for (auto const& wu : this->work_units) {
                bool belongs_to_this = this->contains(this->x, this->y, this->width, this->height, wu.x, wu.y);
                if (!belongs_to_this) {
                    v->push_back(wu);
                }
            }
            return v;
        }

        /**
         * Remove the work unit that do not belong to the cell anymore. 
         * It removes the same work unit than scan() returns.
         */
        void remove() {
            auto it = this->get_first_work_unit();
            auto end = this->get_last_work_unit();

            for (; it != end; std::advance(it, 1)) {
                bool belongs_to_this = this->contains(this->x, this->y, this->width, this->height, it->x, it->y);
                if (!belongs_to_this) this->work_units.erase(it);
            }
        }

        /**
         * Compute the distance between the center of the cell and a work unit
         * @param wu a work unit
         * @return the distance to the work unit
         */
        float distance2(work_unit_t wu) {
            float P1[2] = {this->x + this->width / 2, this->y + this->height / 2},
            P2[2] = {wu.x, wu.y};
            return std::pow(P1[0] - P2[0], 2) - std::pow(P1[1] - P2[1], 2);
        }

    private:

        /**
         * Physically contains a work unit
         * @param x box x position
         * @param y box y position
         * @param width box width
         * @param height box height
         * @param px work unit x position
         * @param py work unit y position
         * @return true if contained false otherwise
         */
        inline bool contains(float x, float y, float width, float height, float px, float py) {
            return (x <= px && y <= py && px <= x + width && py <= y + height) ? true : false;
        }
    };

    /**
     * Decompose a square space into atomic cells, and mark
     * @param startx X top left starting position of the cell
     * @param starty Y top left starting position of the cell
     * @param simbox_width_size width of the space to decompose
     * @param simbox_height_size height of the space to decompose
     * @return 
     */
    ptr_t<std::vector<atomic_cell_t> > decompose_space(float startx, float starty, float simbox_width_size, float simbox_height_size) {
        ptr_t<std::vector<atomic_cell_t> > v(new std::vector<atomic_cell_t>());
        if (simbox_width_size <= 0.0 || simbox_width_size <= 0.0) return v;
        bool is_bordering_cell_east_west = false, is_bordering_cell_north_south = false;
        for (double cell_xpos = startx; cell_xpos < (simbox_width_size + startx); cell_xpos += ATOMIC_CELL_WIDTH) {
            is_bordering_cell_east_west = cell_xpos == startx || ((cell_xpos + ATOMIC_CELL_WIDTH) >= (simbox_width_size + startx));
            for (double cell_ypos = starty; cell_ypos < (simbox_height_size + starty); cell_ypos += ATOMIC_CELL_HEIGHT) {
                is_bordering_cell_north_south = cell_ypos == starty || ((cell_ypos + ATOMIC_CELL_HEIGHT) >= (simbox_height_size + starty));
                atomic_cell_t c(cell_xpos, cell_ypos, is_bordering_cell_east_west || is_bordering_cell_north_south);
                v->push_back(c);
            }
        }
        return v;
    }

    /**
     * Decompose a square space into atomic cells, and mark
     * @param startx X top left starting position of the cell
     * @param starty Y top left starting position of the cell
     * @param simbox_width_size width of the space to decompose
     * @param simbox_height_size height of the space to decompose
     * @return 
     */
    ptr_t<std::vector<atomic_cell_t> > create_space(float startx, float starty, float simbox_width_size, float simbox_height_size) {
        ptr_t<std::vector<atomic_cell_t> > v(new std::vector<atomic_cell_t>());
        if (simbox_width_size <= 0.0 || simbox_width_size <= 0.0) return v;
        bool is_bordering_cell_east_west = false, is_bordering_cell_north_south = false;
        for (double cell_xpos = startx; cell_xpos < (simbox_width_size + startx); cell_xpos += ATOMIC_CELL_WIDTH) {
            is_bordering_cell_east_west = cell_xpos == startx || ((cell_xpos + ATOMIC_CELL_WIDTH) >= (simbox_width_size + startx));
            for (double cell_ypos = starty; cell_ypos < (simbox_height_size + starty); cell_ypos += ATOMIC_CELL_HEIGHT) {
                is_bordering_cell_north_south = cell_ypos == starty || ((cell_ypos + ATOMIC_CELL_HEIGHT) >= (simbox_height_size + starty));
                atomic_cell_t c(cell_xpos, cell_ypos, is_bordering_cell_east_west || is_bordering_cell_north_south);
                v->push_back(c);
            }
        }
        return v;
    }

    inline double bound_between(double min, double max, double actual_value) {
        return actual_value < min ? min : actual_value > max ? max : actual_value;
    }

    /**
     * Initialize N new work units randomly following a uniform probability dist.
     * The work units won't be closer that the min_interaction_dist_sqrt value.
     * @param n number of work unit (int)
     * @param work_units vector to insert the work units to
     * @param min_interaction_dist_sqrt the minimal interaction distance (float)
     * @param T0 velocity factor (float)
     * @param xbox x top left position of the box
     * @param ybox y top left position of the box
     * @param simsizex x size of the box
     * @param simsizey y size of the box 
     * @return the number of work unit effectively created
     */
    template<typename t_distribution>
    int init_work_unit_random(int n,
            std::vector<work_unit_return_t>& work_units,
            float xbox = 0.0f,
            float ybox = 0.0f,
            float simsizex = 1.0f,
            float simsizey = 1.0f,
            float distribution_parameter_a = 0.0f,
            float distribution_parameter_b = 1.0f,
            float min_interaction_dist_sqrt = 1e-2,
            float T0 = 1.0f) {
        using distribution_type = typename std::enable_if <
                std::is_same<t_distribution, std::uniform_real_distribution<double > >::value ||
                std::is_same<t_distribution, std::uniform_real_distribution<float > >::value ||
                std::is_same<t_distribution, std::normal_distribution<double > >::value, t_distribution >::type;

        const int MAX_INIT_TRIALS = 1000;
        float min_r2 = min_interaction_dist_sqrt*min_interaction_dist_sqrt;
        auto wu_builder = work_unit_builder_t::get_instance();
        work_units.clear(); //erase everything

        std::random_device rd;
        std::mt19937 mt(rd());
        distribution_type dist(distribution_parameter_a, distribution_parameter_b);
        
        for (int i = 0; i < n; ++i) {
            float r2 = 0;

            double R = T0 * std::sqrt(-2 * std::log(drand48()));
            double T = 2 * M_PI * drand48();
            double velx = (float) (R * std::cos(T));
            double vely = (float) (R * std::sin(T));
            wu_builder = wu_builder.with_velx(velx).with_vely(vely);
            ///* Choose new point via rejection sampling 
            float posx, posy;
            for (int trial = 0; r2 < min_r2 && trial < MAX_INIT_TRIALS; ++trial) {

                posx = (float) bound_between(0.0, 1.0, dist(mt)) * simsizex + xbox;
                posy = (float) bound_between(0.0, 1.0, dist(mt)) * simsizey + ybox;

                for (int j = 0; j < i; ++j) {
                    float dx = posx - (work_units.at(j).x);
                    float dy = posy - (work_units.at(j).y);
                    r2 = dx * dx + dy*dy;
                    if (r2 < min_r2)
                        break;
                }
            }
            
            wu_builder = wu_builder.with_posx(posx).with_posy(posy);

            work_units.push_back(wu_builder.build());

            /* If it takes too many trials, bail and declare victory! */
            if (i > 0 && r2 < min_r2) return i;
        }
        return n;
    }

    void bind_cell(std::vector<atomic_cell_t>& cells, std::vector<work_unit_return_t> work_units) {
        int current_checking_index = 0;
        int work_unit_index = 0;
        while (work_unit_index < work_units.size()) { // O(n*a), a << n => O(n)
            auto wu = work_units[work_unit_index];
            for (auto& cell : cells) {
                if (cell.contains(wu)) {
                    cell.add_work_unit(wu);
                    break;
                }
            }
            work_unit_index++;
        }
    }
}
#endif /* ATOMIC_CELLS_HPP */

