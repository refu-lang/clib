/**
 * @author: Lefteris Karapetsas
 * @licence: BSD3 (Check repository root for details)
 */
#include <rfbase/parallel/rf_threading.h>

#include <rfbase/utils/log.h>
#include <rfbase/persistent/buffers.h>
#include <rfbase/refu.h>

bool rf_init_thread_specific()
{
    if (!rf_persistent_buffers_activate_ts(RF_DEFAULT_TS_MBUFF_INITIAL_SIZE,
                                           RF_DEFAULT_TS_SBUFF_INITIAL_SIZE)) {
        RF_ERROR(
            "Could not activate the persistent data for thread %#010x",
            rf_thread_get_id()
        );
        return false;
    }

    return true;
}


void rf_deinit_thread_specific()
{
    rf_persistent_buffers_deactivate_ts();
}
