entity = {
};

model1 = field:load_model(30);
model1:set_position_triangle(100, 100, 0, 1);
model1:set_speed(150);
model1:set_visible(true);
model1:set_solid(true);
model1:set_solid_range(30);

model2 = field:load_model(100);
field:set_model_to_character(0, model2);
model2:set_speed(150);
model2:set_solid_range(30);

--field:lock_walkmesh(0, true);



entity["Model1"] = {
    setup = function(self)
        model1:turn_to_model(model2, Model.CLOCKWISE, 3);
        model1:offset_to_position(100, 100, 500, Field.SMOOTH, 2);
        model1:set_offset_wait();
        model1:offset_to_position(0, 0, 0, Field.LINEAR, 1);
        model1:move_to_position(200, 0, false);

        return 0;
    end;
};



entity["Model2"] = {
    setup = function(self)
        model2:move_to_position(10, 10, true);
        model2:set_animation_default("1", 1);
        model2:set_direction(90);
        model2:climb_to_position(300, 0, 250, 5, Model.DOWN_TO_UP);
        local triangle_id = model2:get_triangle();
        if triangle_id == 5 then
            field:lock_pc(true);
            model2:set_direction(-90);
            model2:set_animation_default("5", 1);
            script:wait(0.5);
            model2:jump_to_position(0, 0, 0, 0.567);
            script:wait(0.667);
            --field:lock_walkmesh(0, false);
            field:lock_pc(false);
        end;

        return 0;
    end;
};