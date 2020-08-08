#include "route_planner.h"
#include <algorithm> // for sort
#include <vector>
#include <iostream>
#include <cstdlib>

RoutePlanner::RoutePlanner(RouteModel &model, float start_x, float start_y, float end_x, float end_y): m_Model(model) {
    // Convert inputs to percentage:
    start_x *= 0.01;
    start_y *= 0.01;
    end_x *= 0.01;
    end_y *= 0.01;

  	start_node = &m_Model.FindClosestNode(start_x, start_y);
  	end_node = &m_Model.FindClosestNode(end_x, end_y);
}


float RoutePlanner::CalculateHValue(RouteModel::Node const *node) {
  	return node->distance((*end_node));
}


void RoutePlanner::AddNeighbors(RouteModel::Node *current_node) {
  	current_node->FindNeighbors();
    for (RouteModel::Node * n : current_node->neighbors){
      	if (n->visited == false){  
            n->parent = current_node;
            n->h_value = CalculateHValue(n);
          	n->g_value = current_node->g_value + current_node->distance(*n); // g + d;
            open_list.push_back(n);
            n->visited = true;
        }
 	}
}


RouteModel::Node *RoutePlanner::NextNode() {
    // This is a lambda function
    auto Compare = [](RouteModel::Node* a, RouteModel::Node* b){
        float f1 = a->h_value + a->g_value;
        float f2 = b->h_value + b->g_value;
        return f1 > f2;
    };
    // sort in descending order
    std::sort(open_list.begin(), open_list.end(), Compare);
    RouteModel::Node* lowest_node = open_list.back();
    open_list.pop_back();
    return lowest_node;
}


std::vector<RouteModel::Node> RoutePlanner::ConstructFinalPath(RouteModel::Node *current_node) {
    // Create path_found vector
    distance = 0.0f;
    std::vector<RouteModel::Node> path_found;

    // TODO: Implement your solution here.
  	while ((*current_node).parent != nullptr){
      	distance += current_node->distance((*(*current_node).parent));
      	path_found.insert(path_found.begin(), (*current_node));
      	current_node = (*current_node).parent;
    }	
  	path_found.insert(path_found.begin(), (*current_node));
    distance *= m_Model.MetricScale(); // Multiply the distance by the scale of the map to get meters.
    return path_found;
}


void RoutePlanner::AStarSearch() {
    RouteModel::Node *current_node = nullptr;

    // TODO: Implement your solution here.
  	start_node->visited = true;
  	start_node->h_value = CalculateHValue(start_node);
    start_node->g_value = 0;
    AddNeighbors(start_node); 
  
  	while (open_list.size() > 0) {
      	current_node = NextNode();
      	if (current_node->x == end_node->x && current_node->y == end_node->y){
          	m_Model.path = ConstructFinalPath(current_node);
          	return;
        }
      	AddNeighbors(current_node);
    }
}