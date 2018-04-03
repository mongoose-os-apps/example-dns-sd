/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "common/cs_dbg.h"

#include "mgos_app.h"
#include "mgos_dns_sd.h"
#include "mgos_event.h"
#include "mgos_net.h"

static void net_ev_handler(int ev, void *ev_data, void *arg) {
  if (ev != MGOS_NET_EV_IP_ACQUIRED) return;
  LOG(LL_INFO, ("###"));
  LOG(LL_INFO, ("### Navigate to http://%s/ in your browser",
                mgos_dns_sd_get_host_name()));
  LOG(LL_INFO, ("###"));
  (void) ev_data;
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  mgos_event_add_group_handler(MGOS_EVENT_GRP_NET, net_ev_handler, NULL);
  return MGOS_APP_INIT_SUCCESS;
}
