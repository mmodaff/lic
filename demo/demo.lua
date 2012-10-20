print "LIC Demo"

PrintLic()
PrintString("This is PrintString")

print(Return0())
print(AddOne(5))

local dummy = DummyClass()
print(dummy:GetX())
dummy:SetX(5)
dummy:PrintX()
dummy.Z = 5
print("Z: " .. dummy.Z)

print(dummy:GetX() + 1)

local d = DerivedClass(10)
d:SetX(9)
print(d:GetX())
d:PrintY()
print(d.Z)
d.Z = 9
print(d.Z)