/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
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
