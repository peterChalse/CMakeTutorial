message(STATUS "[info/test_add_custom_target] hello add_custom_target")

add_custom_target(mycmd
    ALL 
    COMMENT "make mycmd!!!"
    COMMAND echo "hello add_custom_target"
    )