Printf
Tanner and I (David) created a function copy of the function printf.
we made our copy function so that it would go character by character until it found a %.
Once the % was found it went throught a function we called print_op were this function would determine which format specifier was trying to be used.
After the specifier has been recognized it is sent through the _printf function where the chosen specifier gets inputed into the
corisponding funtion.
(ex. %d goes to function _int)
The specifier then goes through said function then gets routed back to the prinf function.
Then output is printed out
