-- Model related
-- model represents models in game. All 3d objects are models.
-- this need to be created first via field method.
-- please note that all script halting things must be in same entity
-- else behavior is unpredictable.

-- 0xA5 XYZI
-- set_position_triangle(const float x, const float y, const float z, const int triangle_id)

-- 0xA9 CMOVE rotate = 1
-- 0xAD FMOVE rotate = 0
-- halts script execution until complete
-- move_to_position(const float x, const float y, const bool rotate)

-- 0xAB TURA
-- halts script execution until complete
-- turn_to_model(Model* model, const TurnDirection turn_direction, const int steps)

-- 0xB2 MSPED
-- set_speed(const int speed)

--  0xB5 TURN
-- halts script execution until complete
-- turn_to_direction(const float direction, const TurnDirection turn_direction, const TurnType turn_type, const int steps)

-- 0xC0 JUMP
-- halts script execution until complete
-- jump_to_position(const float x, const float y, const int triangle_id, const int steps)

--  0xC2 LADER
-- halts script execution until complete
-- climb_to_position(const float x, const float y, const float z, const int triangle_id, const ClimbMovement climb_movement, const float direction)

-- 0xC6 SLIDR
-- 0xD7 SLDR2
-- set_solid_range(const int solid_range)

-- 0xC7 SOLID
-- set_solid(const bool is_solid)

-- enums
-- ClimbMovement
-- UP_TO_DOWN
-- DOWN_TO_UP
-- LEFT_TO_RIGHT
-- RIGHT_TO_LEFT

-- TurnType
-- NONE
-- LINEAR
-- SMOOTH

-- TurnDirection
-- CLOCKWISE
-- ANTICLOCKWISE
-- CLOSEST



-- Field related
-- field is a global object. It exist since start of scripting system.
-- it manage all fields data such as model creating and so on.

-- 0xA0 PC
-- creates new model and assosiate it with character
-- if character is party leader then set model visible,
-- solid and talkable and give control to player.
-- Model* load_model(const int character_id)



entity = {
};

model1 = field:load_model(1);
model1:set_position_triangle(100, 100, 0, 1);
model1:set_speed(5);
model1:set_solid(true);
model1:set_solid_range(30);

model2 = field:load_model(0);
model2:set_position_triangle(-100, -100, 0, 1);
model2:set_speed(5);
model2:set_solid_range(30);



entity["Model1"] = {
    setup = function(self)
        model1:turn_to_model(model2, Model.CLOCKWISE, 100);
        model1:move_to_position(200, 0, true);
        return 0;
    end
};



entity["Model2"] = {
    setup = function(self)
        model2:move_to_position(10, 10, false);
        model2:climb_to_position(300, 0, 200, 5, Model.DOWN_TO_UP, 90);
        model2:jump_to_position(0, 0, 0, 30);
        return 0;
    end
};