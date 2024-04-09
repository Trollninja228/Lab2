def snake_to_camel(s):
    words = s.split('_')
    camel_case_string = words[0]
    for word in words[1:]:
        camel_case_string += word.capitalize()
    return camel_case_string

# Example usage:
snake_case_string = "hello_world_how_are_you"
print(snake_case_string.split('_'))
camel_case_string = snake_to_camel(snake_case_string)
print(camel_case_string)
import re

def split_at_uppercase(s):
    return re.findall('[A-Z][^A-Z]*', s)

# Example usage:
input_string = "HelloWorldIAmVoldemort"
split_string = split_at_uppercase(input_string)
print(split_string)
st="HELL"
print(list(st)[0])