unit graderlib;
interface
function Theory(M,L,W: longint): longint;
implementation
uses gradershare;
   function Theory(M,L,W: longint): longint;
   begin
      if (M<1) or (M>6) or (L<1) or (L>10) or (W<1) or (W>6) then halt(92);
      cnt := cnt + 1;
      Theory := 0;
      if (mm <> M) then Theory := 1
      else if (random(2) = 1) and (ll <> L) then Theory := 2
      else if (random(2) = 1) and (ww <> W) then Theory := 3
      else if (random(2) = 1) and (mm <> M) then Theory := 1
      else if (ll <> L) then Theory := 2
      else if (ww <> W) then Theory := 3
      else gotit := 1;
   end;
begin
end.
