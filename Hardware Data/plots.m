temp = data.extractTimetable;
t1 = temp.Time;
t2 = temp.("Discrete Derivative");

%t2 = t2(:,2);

plot(t1, t2)