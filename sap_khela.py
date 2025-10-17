import turtle
import time
import random

delay = 0.2
score = 0
high_score = 0

# Set up the screen
wn = turtle.Screen()
wn.title("Snake Game")
wn.bgcolor("black")
wn.setup(width=600, height=600)
wn.tracer(0)

# Snake head
head = turtle.Turtle()
head.shape("square")
head.color("green")
head.penup()
head.goto(0, 0)
head.direction = "stop"

# Snake food
food = turtle.Turtle()
food.shape("circle")
food.color("red")
food.penup()
food.goto(0, 100)

segments = []

# Scoreboard
sc = turtle.Turtle()
sc.speed(0)
sc.color("white")
sc.penup()
sc.hideturtle()
sc.goto(0, 260)
sc.write("Score: 0  High Score: 0", align="center", font=("Courier", 24, "normal"))

# Functions
def go_up():
    if head.direction != "down":
        head.direction = "up"

def go_down():
    if head.direction != "up":
        head.direction = "down"

def go_left():
    if head.direction != "right":
        head.direction = "left"

def go_right():
    if head.direction != "left":
        head.direction = "right"

def move():
    if head.direction == "up":
        y = head.ycor()
        head.sety(y + 20)
    if head.direction == "down":
        y = head.ycor()
        head.sety(y - 20)
    if head.direction == "left":
        x = head.xcor()
        head.setx(x - 20)
    if head.direction == "right":
        x = head.xcor()
        head.setx(x + 20)

# Keyboard bindings
wn.listen()
wn.onkey(go_up, "Up")
wn.onkey(go_down, "Down")
wn.onkey(go_left, "Left")
wn.onkey(go_right, "Right")

# Main game loop
while True:
    wn.update()

    # Check for collision with border
    if (head.xcor() > 290 or head.xcor() < -290 or
        head.ycor() > 290 or head.ycor() < -290):
        time.sleep(1)
        head.goto(0, 0)
        head.direction = "stop"
        for segment in segments:
            segment.goto(1000, 1000)
        segments.clear()
        score = 0
        sc.clear()
        sc.write(f"Score: {score}  High Score: {high_score}", align="center", font=("Courier", 24, "normal"))

    # Check for collision with food
    if head.distance(food) < 20:
        x = random.randint(-290, 290)
        y = random.randint(-290, 290)
        food.goto(x, y)

        # Add a segment
        new_segment = turtle.Turtle()
        new_segment.shape("square")
        new_segment.color("lightgreen")
        new_segment.penup()
        segments.append(new_segment)

        score += 10
        if score > high_score:
            high_score = score
        sc.clear()
        sc.write(f"Score: {score}  High Score: {high_score}", align="center", font=("Courier", 24, "normal"))

    # Move the end segments first in reverse order
    for i in range(len(segments)-1, 0, -1):
        x = segments[i-1].xcor()
        y = segments[i-1].ycor()
        segments[i].goto(x, y)
    if segments:
        segments[0].goto(head.xcor(), head.ycor())

    move()

    # Check for collision with body
    for segment in segments:
        if segment.distance(head) < 20:
            time.sleep(1)
            head.goto(0, 0)
            head.direction = "stop"
            for segment in segments:
                segment.goto(1000, 1000)
            segments.clear()
            score = 0
            sc.clear()
            sc.write(f"Score: {score}  High Score: {high_score}", align="center",  font=("Courier", 24, "normal"))

    time.sleep(delay)
wn.mainloop()