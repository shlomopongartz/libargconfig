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
	.entries    = 0,
	.max        = 0,
	.mean       = 0,
	.min        = ULONG_MAX,
	.var        = 0,
	.percentile = {0, 0, 0},
};

unsigned long stats_std(struct stats *thisstats)
{

	unsigned long ret;

	ret = thisstats->var / thisstats->entries;
	ret -= (thisstats->mean * thisstats->mean) /
		(thisstats->entries * thisstats->entries);
	ret = sqrt(ret);

	return ret;
}

void stats_strstats(char *str, struct stats *thisstats)
{
	sprintf(str,"stats: mean = %lu: std = %lu: min = %lu: max = %lu: percentile (%2.1f%%) = %lu",
		thisstats->mean / thisstats->entries,
		stats_std(thisstats),
		thisstats->min, thisstats->max,
		100*(double)(thisstats->percentile.below) /
		(thisstats->percentile.below + thisstats->percentile.above),
		thisstats->percentile.target);
}

void stats_process(struct stats *thisstats, unsigned long val)
{
	if (val < thisstats->min)
		thisstats->min = val;
	if (val > thisstats->max)
		thisstats->max = val;
	thisstats->entries++;
	thisstats->mean += val;
	thisstats->var += (val * val);

	if (!thisstats->percentile.target)
		return;

	struct percentile *this = &thisstats->percentile;

	if (val > this->target)
		this->above++;
	if (val < this->target)
		this->below++;
}

void stats_settarget(struct stats *thisstats, double target)
{
	thisstats->percentile.target = target;
	thisstats->percentile.above = 0;
	thisstats->percentile.below = 0;
}
