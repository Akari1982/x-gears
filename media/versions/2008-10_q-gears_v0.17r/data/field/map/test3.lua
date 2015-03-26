entity = {
};



entity["Text1"] = {
    on_start = function(self)
        script:request("Text1", "on_talk", 3);
        script:request("Text2", "script1", 3);
        script:request_start_wait("Text2", "script2", 4);
        script:request_end_wait("Text1", "on_collide", 2);

        message:set_style(7, Message.TRANSPARENT);
        message:show_text_wait(7, "Test complete!", 0, 0, 640, 480);

        return 0;
    end;

    on_talk = function(self)
        message:show_text_wait(1, "Text1:on talk", 0, 0, 100, 100);

        return 0;
    end;

    on_collide = function(self)
        message:show_text_wait(1, "Text1:on collide", 0, 0, 100, 100);

        return 0;
    end;
};



entity["Text2"] = {
    on_start = function(self)

        return 0;
    end;

    script1 = function(self)
        message:show_text_wait(2, "Text2:script1", 100, 0, 100, 100);

        return 0;
    end;

    script2 = function(self)
        message:show_text_wait(2, "Text2:script2", 100, 0, 100, 100);

        return 0;
    end;
};



entity["Text3"] = {
    on_start = function(self)
        message:show_text_wait(3, "Text3:setup", 200, 0, 100, 100);

        return self.script1(self);
    end;

    script1 = function(self)
        message:show_text_wait(3, "Text3:script1", 200, 0, 100, 100);

        return 0;
    end;
};
