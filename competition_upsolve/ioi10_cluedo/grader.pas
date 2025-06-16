program grader;
   uses gradershare, cluedo;
   var maxcnt:longint;
begin
   maxcnt := 0;
   while not eof do begin
      readln(MM,LL,WW);
      cnt := 0;
      gotit := 0;
      Solve;
      if cnt > maxcnt then maxcnt := cnt;
      if gotit = 0 then begin
         writeln('NO');
         halt(91);
      end;
   end;
   writeln('OK ',maxcnt);
end.
