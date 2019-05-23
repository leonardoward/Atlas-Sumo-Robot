function [Vr]=Vright_unicycle(V,W,LENGTH_ROBOT,RADIUS_WHEEL)
    Vr=(((2*V)+(W*LENGTH_ROBOT))/(2*RADIUS_WHEEL));
end