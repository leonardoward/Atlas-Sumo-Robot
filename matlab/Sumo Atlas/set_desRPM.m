function [des_RPM_right,des_RPM_left,V_right,V_left]=set_desRPM(V,W,LENGTH_ROBOT,RADIUS_WHEEL)
    V_right=Vright_unicycle(V,W,LENGTH_ROBOT,RADIUS_WHEEL);
    des_RPM_right=RPM_from_VEL(V_right,RADIUS_WHEEL);
    V_left=Vleft_unicycle(V,W,LENGTH_ROBOT,RADIUS_WHEEL);
    des_RPM_left=RPM_from_VEL(V_left,RADIUS_WHEEL);
end

