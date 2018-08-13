/* Copyright (C) 2013 Codership Oy <info@codership.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#ifndef WSREP_THD_H
#define WSREP_THD_H

#include "sql_class.h"

int wsrep_show_bf_aborts (THD *thd, SHOW_VAR *var, char *buff);
void wsrep_client_rollback(THD *thd);
void wsrep_replay_transaction(THD *thd);
void wsrep_create_appliers(long threads);
void wsrep_create_rollbacker();

int  wsrep_abort_thd(void *bf_thd_ptr, void *victim_thd_ptr,
                                my_bool signal);

extern void  wsrep_thd_set_PA_safe(void *thd_ptr, my_bool safe);
extern my_bool  wsrep_thd_is_BF(void *thd_ptr, my_bool sync);
extern int wsrep_thd_conflict_state(void *thd_ptr, my_bool sync);
//extern "C" my_bool  wsrep_thd_is_BF(void *thd_ptr, my_bool sync);
extern "C" my_bool  wsrep_thd_is_BF_or_commit(void *thd_ptr, my_bool sync);
extern "C" my_bool  wsrep_thd_is_local(void *thd_ptr, my_bool sync);
int  wsrep_thd_in_locking_session(void *thd_ptr);

#endif /* WSREP_THD_H */
