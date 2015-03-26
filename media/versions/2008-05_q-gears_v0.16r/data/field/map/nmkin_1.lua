entity = {
};

model = field:load_model(100);
field:set_model_to_character(0, model);
model:set_position_triangle(-690, 2314, -275, 30);
model:set_speed(150);
model:set_visible(true);
model:set_solid(true);



entity["Model"] = {
    setup = function(self)
        return 0;
    end
};
