/*
 *  traceback.h
 *  glia
 *
 *  Created by Deniz Kural on 12/26/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TRACEBACK_H  
#define TRACEBACK_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <sstream>

#include "gliamodels.h"
#include "nodealign.h"


// bt := backtrace return object
struct bt {
    int x;
    int y;
    std::string backstr;
    sn* node;
bt() : node(NULL) { }
};


// mbt := data structure for trace report
struct mbt {
    int x;
    int y;
    std::string cigar;
    std::vector<sn*> node_list;
    std::string node_name;				// why use outside of context?
};


// recursive backtrack
bt backtrack(sn* node,
	     int x, int y,
	     std::vector<bt>& trace,
	     std::string& backstr,
	     std::vector<sn*> &node_list);

// mbt := data structure for trace report
struct mbt;

// master backtrack
bt master_backtrack(sn* node, mbt &trace_report);


#endif
