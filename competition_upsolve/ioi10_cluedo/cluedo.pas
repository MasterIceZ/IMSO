unit cluedo;

interface
   procedure Solve;
implementation
   uses graderlib;
   procedure Solve;
      var r: longint;
   begin
      r := Theory(1,2,3);
      if r <> 0 then r := Theory(3,2,1);
      if r <> 0 then r := Theory(4,4,4);
   end;
begin
end.
