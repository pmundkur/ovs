/*-
 * Copyright (c) 2014 Jong Hun Han
 * Copyright (c) 2014 SRI International
 * All rights reserved.
 *
 * This software was developed by SRI International and the University of
 * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-11-C-0249
 * ("MRC2"), as part of the DARPA MRC research programme.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* NOTE: once the switch supports discoverable configuration, this file will not
   be needed.
*/

/* Basic address map for the onetable switch, from
   NetFPGAOneTableRegsNoArbSwitchTop.  */

#define DEVICE_BASE_ADDR    0x70010000
#define TCAM_BASE_OFFSET    (36 * 4)
#define PIPE_BASE_OFFSET    ((36 + 46) * 4)

bs_info_t bsw_1table = {
  .dev                  = -1,
  .device_base_addr     = DEVICE_BASE_ADDR,
  .stats_base_addr      = DEVICE_BASE_ADDR,
  .tcam_base_addr       = DEVICE_BASE_ADDR + TCAM_BASE_OFFSET,
  .pipeline_base_addr   = DEVICE_BASE_ADDR + PIPE_BASE_OFFSET,
  .num_ports            = 8,   /* TestPipeline in testlib */
  .tcam_num_entries     = 10,  /* NumEntries in OneTableRegsSwitchPipeline */
};

tcam_cfg_t bsw_cfg = {
  .dev          = -1,
  .base_addr    = NULL,
  .status_ofs   = 0,                    /*        status ofs */
  .set_ofs      = 1,                    /*       setRegs ofs */
  .get_ofs      = 1 + 22,               /*       getRegs ofs */
  .trig_ofs     = 1 + (2 * 22),         /*       trigger ofs */

  .key_size     = 1,                    /*          key size */
  .val_size     = 19,                   /*  encoded val size */
};