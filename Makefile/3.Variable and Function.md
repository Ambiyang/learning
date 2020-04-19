## Variable
### Immediate and latency variables
If a variable is assigned by := then it is a immediate variable otherwise(=) is a latency variables
```
HELLO = Good  
TIME = morning!  
IMMEDIATE_STRING := $(HELLO) $(TIME)  
LATENCY_STRING = $(HELLO) $(TIME)  
$(info $(IMMEDIATE_STRING))  
$(info $(LATENCY_STRING))  
TIME = afternoon!  
$(info $(IMMEDIATE_STRING))  
$(info $(LATENCY_STRING))  
```
The output is  
```
Good morning!  
Good morning!  
Good morning!  
Good afternoon!  
```
### Local variable
```
N = 1  
$(BIN): N = 2  
$(BIN):$(OBJS)  
	@echo "BIN: N = $(N)"  
	gcc -o $(BIN) $(OBJS)  
```
The output is  
```
BIN: N = 2
```
Note:All the dependencies of BIN share the same local N with value 2  

## Function
```
SRCS = player.c lcd.c usb.c media.c hello.h main.txt
OBJS = $(subst .c,.o,$(strip $(SRCS))) #strip removes spaces in SRCS ,subst replaces .c to .o
DEPS = $(patsubst %.c,%.d,$(SRCS)) #patsubst is wildcard substitute
DEPS2 = $(SRCS:.c=.d) #this has the same effect as DEPS
FILTER = $(filter %.c %.h, $(SRCS)) #find the files with suffix .c .h
```
for each
```
A = 1 3 4  
B = $(foreach i,$(A),$(addprefix 0.,$(i))) # B = 0.1 0.3 0.4  
C = $(foreach i,$(A),$(addsuffix .0,$(i))) # C = 1.0 3.0 4.0
```
shell is also allowed in makefile
```
$(shell mkdir -p s1)
```
