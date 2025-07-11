//

module top_module (
    input too_cold,
    input too_hot,
    input mode,
    input fan_on,
    output heater,
    output aircon,
    output fan
); 
    
    assign heater = ((too_cold==1)&(mode==1)) ? 1'b1:
        1'b0;
    assign aircon = ((too_hot==1)&(mode==0)) ? 1'b1:
        1'b0;
    assign fan = ((heater==1)|(aircon==1)|(fan_on==1))?1'b1:
        1'b0;
endmodule