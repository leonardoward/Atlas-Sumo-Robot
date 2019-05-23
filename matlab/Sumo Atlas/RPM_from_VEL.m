function [RPM]=RPM_from_VEL(V,RADIUS_WHEEL)
  %Convertimos de V (m/s) a W (rad/s)
  W = V/RADIUS_WHEEL;
  %//Convertimos de rad/s a rev/min 
  RPM = W*9.5492;
end