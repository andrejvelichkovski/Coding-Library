/*
    Implementation of Segment Tree
    By default, it finds minimum, maximum value and sum in a range
*/
#include <bits/stdc++.h>
using namespace std;

class node_values {
public:
    int max_value, min_value, sum;
};

node_values EMPTY;

class node {
    // Variables for the Segment Tree itself
    int left_bound, right_bound;
    node *left_child, *right_child;

    // Variables for the stored values
public:
    node_values current;

    node(int _lb, int _rb) {
        left_bound = _lb;
        right_bound = _rb;

        left_child = right_child = NULL;
    }

    void set_leaf_value(int arr_value) {
        current = {arr_value, arr_value, arr_value};
    }

    node_values merge(node_values left_value, node_values right_value) {
        node_values curr = {};

        curr.min_value = min(left_value.min_value, right_value.min_value);
        curr.max_value = max(left_value.max_value, right_value.max_value);

        curr.sum = left_value.sum + right_value.sum;
    }

    void build(int arr[]) {
        if(left_bound == right_bound) {
            set_leaf_value(arr[left_bound]);
            return;
        }

        int mid = (left_bound + right_bound) / 2;

        if(left_child == NULL) left_child = new node(left_bound, mid);
        if(right_child == NULL) right_child = new node(mid+1, right_bound);

        left_child->build(arr);
        right_child->build(arr);
    }

    node_values query(int query_left, int query_right) {
        if(right_bound < query_left || left_bound > query_right) return EMPTY;
        if(left_bound >= query_left && right_bound <= query_right) return current;

        node_values left = left_child->query(query_left, query_right);
        node_values right = right_child->query(query_left, query_right);

        return merge(left, right);
    }

    void update(int position, int new_value) {
        if(left_bound == right_bound) {
            set_leaf_value(new_value);
        }
        else {
            int mid = (left_bound + right_bound) / 2;
            if(position <= mid) left_child->update(position, new_value); 
            else right_child->update(position, new_value);

            current = merge(left_child->current, right_child->current);
        }
    }
};

int main() {
    EMPTY = {INT_MIN, INT_MAX, 0};
}