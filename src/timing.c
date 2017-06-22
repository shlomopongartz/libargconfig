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
//     Common time related routines
//
////////////////////////////////////////////////////////////////////////

#include "timing.h"

double timeval_to_secs(struct timeval *t)
{
	return t->tv_sec + t->tv_usec / 1e6;
}

unsigned long elapsed_time(struct timespec *end, struct timespec *start)
{
	return (end->tv_sec * 1e9 + end->tv_nsec) -
		(start->tv_sec * 1e9+ start->tv_nsec);
}
