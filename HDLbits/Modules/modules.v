// The figure below shows a very simple circuit with a sub-module. In this exercise, create one instance of module mod_a, then connect the module's three pins (in1, in2, and out) to your top-level module's three ports (wires a, b, and out). The module mod_a is provided for you — you must instantiate it. 

module top_module ( input a, input b, output out );
    mod_a m(.in1(a), .in2(b),.out(out) );
endmodule