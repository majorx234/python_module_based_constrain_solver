//
//  vf3.hpp
//  VF2Plus
//
//  Created by MajorX234 on 25/09/10.
//  Copyright (c) 2014 Vincenzo Carletti. MajorX234 All rights reserved.
//
#ifndef VF3_HPP
#define VF3_HPP

#include "argraph.hpp"
#include "vf3_sub_state.hpp"

#ifndef VF3BIO
typedef int data_t;
#else
typedef std::string data_t;
#endif

#include "vf3_sub_state.hpp"
#define SUBSTATE_CLASS VF3SubState
#define PARAMETER_K_IF_NEEDED

typedef struct visitor_data_s {
  unsigned long first_solution_time;
  long solutions;
} visitor_data_t;

bool visitor(int n, node_id n1[], node_id n2[], void *state, void *usr_data);

#endif // VF3_HPP
