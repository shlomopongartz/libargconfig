////////////////////////////////////////////////////////////////////////
//
// Copyright 2014 PMC-Sierra, Inc.
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
//   Author: Logan Gunthorpe
//
//   Date:   Oct 23 2014
//
//   Description:
//     Common reporting routines
//
////////////////////////////////////////////////////////////////////////

#ifndef __ARGCONFIG_REPORT_H__
#define __ARGCONFIG_REPORT_H__

#include <stdio.h>
#include <sys/time.h>

void report_transfer_rate_elapsed(FILE * outf, double elapsed_time,
				  size_t bytes);

void report_transfer_rate(FILE * outf, struct timeval *start_time,
			  struct timeval *end_time, size_t bytes);

void report_transfer_bin_rate_elapsed(FILE * outf, double elapsed_time,
				      size_t bytes);
void report_transfer_bin_rate(FILE * outf, struct timeval *start_time,
			      struct timeval *end_time, size_t bytes);

void report_usage_per_4k(FILE * outf, struct timeval *start_time,
			 struct timeval *end_time, size_t bytes);

#endif
