#include "dropout.h"

ASSERT_COMMUNITY_MODULES_MIN_API_VERSION(0,1,0);

#define V_____V DROP

bool process_record_dropout(uint16_t keycode, keyrecord_t *record) {
    if((keycode == DROP) && get_highest_layer(layer_state) > 0){
        clear_oneshot_layer_state(get_highest_layer(layer_state));
        layer_off(get_highest_layer(layer_state));
    }
    return true;
}