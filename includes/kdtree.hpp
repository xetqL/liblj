/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   kdtree.hpp
 * Author: xetql
 *
 * Created on April 28, 2017, 2:16 PM
 */

#ifndef KDTREE_HPP
#define KDTREE_HPP

#include "atomic_cells.hpp"
#include <vector>

/* 
function kdtree (liste de points pointList, int depth)
{
    if pointList is empty
        return nil;

    // Sélectionne l'axe de comparaison en fonction de la profondeur du nœud
    var int axis := depth mod k;

    // trie la liste de points et sélectionne le point médian
    select median by axis from pointList;

    // Crée le nœud courant, et construit récursivement les deux fils
    var tree_node node;
    node.location := median;
    node.leftChild := kdtree(points in pointList before median, depth+1);
    node.rightChild := kdtree(points in pointList after median, depth+1);
    return node;
}
 */

template<typename t_point, int D>
class kdtree_t {
public:
    using kdtree_ptr = std::shared_ptr<kdtree_t>;
    using t_point = std::enable_if<std::is_same<t_point, liblj::work_unit_t>>;

    static kdtree_ptr build(std::vector<t_point> points) {
        
        kdtree_ptr p(new kdtree_t());
        
        p->root = kdtree_t<t_point, D>::build(points, 0);
        
        return p;
    }

    kdtree_t() {
    }

private:
    
    struct kdtree_node {
        kdtree_node* left;
        kdtree_node* right;
        double location;
        t_point* p;
    };
    

    kdtree_node* root;

    static kdtree_node* build(std::vector<t_point> points, int depth) {

        if (points.size() == 0) return nullptr;

        int axis = depth % D; //axis to look at

        std::sort(points.begin(), points.end(), [&] (const t_point& a, const t_point & b) -> bool {
            return a.get_dimension(axis) > b.get_dimension(axis);
        });
        
        std::vector<t_point>::iterator median_point = std::next(points.begin(), (points.size() - 1) / 2);
        std::vector<t_point> left_points(points.begin(), median_point);
        std::vector<t_point> right_points(std::next(median_point, 1), points.end());
        
        kdtree_node* n = new kdtree_node();
        
        if(points.size() == 1) 
            n->p = &(points[0]);
        
        n->left = kdtree_t<t_point, D>::build(left_points, depth+1);
        
        n->right = kdtree_t<t_point, D>::build(right_points, depth+1);
        
        n->location = median_point->get_dimension(axis);
        
        return n;
    }
};

#endif /* KDTREE_HPP */

