/* -*- c++ -*- */
/*
 * Copyright 2007 Free Software Foundation, Inc.
 * 
 * This file is part of GNU Radio
 * 
 * GNU Radio is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 * 
 * GNU Radio is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

// WARNING: this file is machine generated.  Edits will be over written

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gr_dpll_ff.h>
#include <gr_io_signature.h>

gr_dpll_ff_sptr
gr_make_dpll_ff (float period, float gain)
{
  return gr_dpll_ff_sptr (new gr_dpll_ff (period, gain));
}

gr_dpll_ff::gr_dpll_ff (float period, float gain)
  : gr_sync_block ("dpll_ff",
		   gr_make_io_signature (1, 1, sizeof (float)),
		   gr_make_io_signature (1, 1, sizeof (float))),
    d_restart(0),d_pulse_phase(0)
{
  d_pulse_frequency = 1.0/period;
  d_gain = gain;
  d_decision_threshold = 1.0 - 0.5*d_pulse_frequency;
#if 1
  fprintf(stderr,"frequency = %f period = %f gain = %f threshold = %f\n",
	  d_pulse_frequency,
	  period,
	  d_gain,
	  d_decision_threshold);
#endif
  set_history(1); // so we can look behind us
}

int
gr_dpll_ff::work (int noutput_items,
	      gr_vector_const_void_star &input_items,
	      gr_vector_void_star &output_items)
{
  float *iptr = (float *) input_items[0];
  float *optr = (float *) output_items[0];

  for (int i = 0; i < noutput_items; i++){
    optr[i]= (float)0;
    if(iptr[i] ==(float)1) {
      if (d_restart == 0) {
	d_pulse_phase = 1;
      } else {
	if (d_pulse_phase > 0.5) d_pulse_phase += d_gain*(1.0-d_pulse_phase);
	else d_pulse_phase -= d_gain*d_pulse_phase;
      }
      d_restart = 3;
    }
    if (d_pulse_phase > d_decision_threshold) {
      d_pulse_phase -= 1.0;
      if (d_restart > 0) {
	d_restart -= 1;
	optr[i] = (float)1;
      }
    }
    d_pulse_phase += d_pulse_frequency;
  }
  return noutput_items;
}
