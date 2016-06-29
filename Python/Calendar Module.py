import calendar

a = list(map(int, input().split()))
a = [a[2], a[0], a[1]]
print(list(calendar.day_name)[calendar.weekday(*a)].upper())