////////////////////////////////////////////////////////////////////////
//
// Copyright 2017 Raithlin Consulint Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License"); you
// may not use this file except in compliance with the License. You may
// obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0 Unless required by
// applicable law or agreed to in writing, software distributed under the
// License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for
// the specific language governing permissions and limitations under the
// License.
//
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
//
//   Author: Stephen Bates
//
//   Date:   June 22 2017
//
//   Description:
//     Common simple stats related routines
//
////////////////////////////////////////////////////////////////////////

#ifndef __ARGCONFIG_STATS_H__
#define __ARGCONFIG_STATS_H__

#include <limits.h>
#include <math.h>
#include <stdio.h>

struct percentile {
	size_t below;
	size_t above;
	unsigned long target;
};

struct stats {
	unsigned long     mean;
	unsigned long     var;
	unsigned long     min;
	unsigned long     max;
	size_t            entries;
	struct percentile percentile;
};

struct stats STATS_INIT;

unsigned long stats_std(struct stats *thisstats);
void stats_strstats(char *str, struct stats *thisstats);
void stats_process(struct stats *thisstats, unsigned long val);
void stats_settarget(struct stats *thisstats, double target);

#endif
