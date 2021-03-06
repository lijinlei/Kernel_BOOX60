#ifndef CYGONCE_DEVS_TS1000_ETH_INL
#define CYGONCE_DEVS_TS1000_ETH_INL
//==========================================================================
//
//      ts1000_eth.inl
//
//      Hardware specifics for Allied Telesyn TS1000 ethernet support
//
//==========================================================================
//####ECOSGPLCOPYRIGHTBEGIN####
// -------------------------------------------
// This file is part of eCos, the Embedded Configurable Operating System.
// Copyright (C) 1998, 1999, 2000, 2001, 2002 Red Hat, Inc.
// Copyright (C) 2002 Gary Thomas
//
// eCos is free software; you can redistribute it and/or modify it under
// the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 or (at your option) any later version.
//
// eCos is distributed in the hope that it will be useful, but WITHOUT ANY
// WARRANTY; without even the implied warranty of MERCHANTABILITY or
// FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
// for more details.
//
// You should have received a copy of the GNU General Public License along
// with eCos; if not, write to the Free Software Foundation, Inc.,
// 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
//
// As a special exception, if other files instantiate templates or use macros
// or inline functions from this file, or you compile this file and link it
// with other works to produce a work based on this file, this file does not
// by itself cause the resulting work to be covered by the GNU General Public
// License. However the source code for this file must still be made available
// in accordance with section (3) of the GNU General Public License.
//
// This exception does not invalidate any other reasons why a work based on
// this file might be covered by the GNU General Public License.
//
// Alternative licenses for eCos may be arranged by contacting Red Hat, Inc.
// at http://sources.redhat.com/ecos/ecos-license/
// -------------------------------------------
//####ECOSGPLCOPYRIGHTEND####
//==========================================================================
//#####DESCRIPTIONBEGIN####
//
// Author(s):    gthomas
// Contributors: gthomas
// Date:         2002-09-03
// Purpose:      
// Description:  
//              
//####DESCRIPTIONEND####
//
//==========================================================================


extern int  hal_ts1000_get_led(void);
extern void hal_ts1000_set_led(int);

#define _get_led()  
#define _set_led(v) 

#define LED_TxACTIVE  2
#define LED_RxACTIVE  1
#define LED_IntACTIVE 0

// Interrupt generated by device
#define FEC_ETH_INT CYGNUM_HAL_INTERRUPT_SIU_LVL1
// Address of PHY (transceiver) device
#define FEC_ETH_PHY 1

// Reset the PHY - analagous to hardware reset
#define FEC_ETH_RESET_PHY()                                     \
    eppc->pio_padat |= 0x00008000;  /* Reset PHY chip */       \
    CYGACC_CALL_IF_DELAY_US(10000);  /* 10ms */                 \
    eppc->pio_padat &= ~0x00008000;   /* Enable PHY chip */

#endif  // CYGONCE_DEVS_TS1000_ETH_INL
// ------------------------------------------------------------------------
