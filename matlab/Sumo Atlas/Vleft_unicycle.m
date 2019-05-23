function [Vl]=Vleft_unicycle(V,W,LENGTH_ROBOT,RADIUS_WHEEL)
    Vl=((2*V)-(W*LENGTH_ROBOT))/(2*RADIUS_WHEEL);
end