// load cursor
// load text
// load image
// load window
// load level

menu = {
    ui_fade    = ui:fade(),
    ui_cursor  = ui:cursor("cursor.png", {0}, {0, 20}),
    m_new_game = ui:message(0, 20000, COLOR_WHITE),
    m_continue = ui:message(0, 20001, COLOR_GRAY),
    background = ui:image("sword.png"),

    input_lock = false;



    start = function(self)
        self.ui_fade:layer(0);
        self.ui_cursor:layer(1);
        self.ui_font:layer(2);
        self.background:layer(3);

        self.ui_fade:fade_out(100, 10);

        self.ui_cursor:position(0, 10);
        self.m_new_game:position(10, 10);
        self.m_continue:position(10, 30);
        self.background:position(0, 0);
    end,



    finish = function(self)
        self.ui_fade:fade_in(0, 10);
    end,



    onupdate = function(self)
    end,



    oninput = function(self, button)
        if not input_lock then
            if button == BUTTON_DOWN then
                self.ui_cursor:move_down;
            elseif button == BUTTON_UP then
                self.ui_cursor:move_up;
            elseif button == BUTTON_OK then
                self.input_lock = true;

                if self.ui_cursor:row == 0 then
                    module_manager:run_module(MODULE_FIELD, 65);
                elseif self.ui_cursor:row == 1 then
                    module_manager:run_module(MODULE_MENU, 15);
                end;
            end;
        end;
    end,
};
