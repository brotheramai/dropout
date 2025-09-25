# Dropout
Simple qmk community module that adds the DROP / V_____V keycode. These keycodes behave like KC_TRNS / _______ except they also turn off the topmost layer.

# Ok, why?
Consider a nav layer that just has the arrow keys
```
 /* arrows
     * ┌───┬───┬───┬───┬───┐              ┌───┬───┬───┬───┬───┐
     * │   │   │   │   │   │              │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┤
     * │   │ < │ ^ │ > │   │              │   │   │   │   │   │
     * ├───┼───┼───┼───┼───┤              ├───┼───┼───┼───┼───┤
     * │   │   │ v │   │   │              │   │   │   │   │   │
     * └───┴───┼───┼───┼───┤              ├───┼───┼───┼───┴───┘
     *         |   │   │   │              │ B │   │   |
     *         └───┴───┴───┘              └───┴───┴───┘
     */
```
Which you might define like this:
```
    [ARROW] = LAYOUT(
        _______,       _______,  _______,  _______,  _______,                    _______,     _______,   _______,     _______,    _______,
        _______,       KC_LEFT,  KC_UP,    KC_RGHT,  _______,                    _______,     _______,   _______,     _______,    _______,
        _______,       _______,  KC_DOWN,  _______,  _______,                    _______,     _______,   _______,     _______,    _______,
        _______,       _______,  _______,  _______,  _______,                    TO(BASE),    _______,   _______,     _______,    _______
    ), 
```

Now when you enter this layer you can arrow around to your heart's content and if you need anything under the arrow layer you just press the key you'd normally press and voilà it works as expected.
But you eventually need one of the keys underneath the arrow keys and when you press it you get an arrow key instead.

Now consider instead if you defined it like this:
```
    [ARROW] = LAYOUT(
        v_____V,       v_____V,  v_____V,  v_____V,  v_____V,                    v_____V,     v_____V,   v_____V,     v_____V,    v_____V,
        v_____V,       KC_LEFT,  KC_UP,    KC_RGHT,  v_____V,                    v_____V,     v_____V,   v_____V,     v_____V,    v_____V,
        v_____V,       v_____V,  KC_DOWN,  v_____V,  v_____V,                    v_____V,     v_____V,   v_____V,     v_____V,    v_____V,
        v_____V,       v_____V,  v_____V,  v_____V,  v_____V,                    TO(BASE),    v_____V,   v_____V,     v_____V,    v_____V
    ), 
```

Now when you start typing with your non-arrow keys you immediately drop out of your arrow layer, so when the time comes to type a character that's hidden by an arrow it's no problem because you aren't in your arrow layer anymore.

There are many other solutions to this problem already, but this one doesn't require you to do anything extra ahead of time. You just press the keys you want to press and your keyboard knows what you mean.