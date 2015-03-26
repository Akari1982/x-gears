entity = {
};

game:variable_set("akari", 999);
game:character_add_to_party(0);
game:character_add_to_party(1);
game:character_add_to_party(2);
game:party_set_size(2);
--game:character_remove_from_party(0);

model1 = field:load_model("Model1", 5803);
model1:set_position_triangle(100, 100, 0, 1);
model1:set_speed(150);
model1:set_visible(true);
model1:set_solid(true);
model1:set_solid_range(35);
model1:set_talk_range(100);
model1:set_talkable(true);

model2 = field:load_sprite("Model2", 5803);
field:set_entity_to_character(model2, 0);
model2:set_direction(0);
model2:set_speed(150);
model2:set_solid_range(30);

field:random_encounter_table(0);
field:random_encounter_on(false);



entity["Text"] = {
    on_start = function(self)
        return 0;
    end;

    on_talk = function(self)
        return 0;
    end;

    on_enter_line = function(self)
        if bit.band(258, hex.to_dec('0xFF')) == 2 then
            fade:fade(255, 0, 0, Fade.SUBTRACT, 480, 0);
        end;

        return 0;
    end;

    on_leave_line = function(self)
        if bit.band(258, hex.to_dec('0xFF')) == 2 then
            fade:fade(255, 0, 0, Fade.SUBTRACT, -120, 255);
        end;

        return 0;
    end;

    on_cross_line = function(self)
        local item = game:item_get(1);
        if item ~= 20 then
            field:pc_lock(true);
            message:set_style(1, Message.TRANSPARENT);
            message:show_text_wait(1, "Fight", 100, 100, 100, 100);
            field:battle_run(300);
            game:item_add(1, 10);
            field:pc_lock(false);
        end;

        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};



entity["trigger2"] = {
    on_start = function(self)
        return 0;
    end;

    on_talk = function(self)
        return 0;
    end;

    on_enter_line = function(self)
        field:pc_slip(false);
        field:line_trigger_on("gateway_to_test2", true);
        return 0;
    end;

    on_leave_line = function(self)
        field:pc_slip(true);
        return 0;
    end;

    on_cross_line = function(self)
        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};



entity["gateway_to_test2"] = {
    on_start = function(self)
        return 0;
    end;

    on_talk = function(self)
        return 0;
    end;

    on_enter_line = function(self)
        return 0;
    end;

    on_leave_line = function(self)
        return 0;
    end;

    on_cross_line = function(self)
        field:jump_to_map(2, 0, 0, 0, 0);
        return 0;
    end;

    on_move_to_line = function(self)
        return 0;
    end;

    on_activate_line = function(self)
        return 0;
    end;
};



entity["Model1"] = {
    on_start = function(self)
        model1:turn_to_model(model2, Entity.CLOCKWISE, 3);
        model1:offset_to_position(100, 100, 500, Field.SMOOTH, 2);
        model1:set_offset_wait();
        model1:offset_to_position(0, 0, 0, Field.LINEAR, 1);
        model1:move_to_position(200, 0, false);

        return 0;
    end;

    on_talk = function(self)
        model1:play_animation_wait("3", 0, -1, 0.5, false);

        return 0;
    end;

    on_collide = function(self)
        return 0;
    end;
};



entity["Model2"] = {
    on_start = function(self)
        return 0;
    end;

    on_talk = function(self)
    end;

    on_collide = function(self)
        return 0;
    end;
};
