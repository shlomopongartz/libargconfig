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

#include "stats.h"

struct stats STATS_INIT = {
	.entries = 0,
	.max     = 0,
	.mean    = 0,
	.min     = ULONG_MAX,
	.var     = 0,
};

unsigned long std(struct stats *thisstats)
{

	unsigned long ret;

	ret = thisstats->var / thisstats->entries;
	ret -= (thisstats->mean * thisstats->mean) /
		(thisstats->entries * thisstats->entries);
	ret = sqrt(ret);

	return ret;
}

void strstats(char *str, struct stats *thisstats)
{
	sprintf(str,"stats: mean = %lu: std = %lu: min = %lu: max = %lu",
		thisstats->mean / thisstats->entries,
		std(thisstats),
		thisstats->min, thisstats->max);
}
