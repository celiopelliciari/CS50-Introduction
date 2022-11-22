import os
from cs50 import SQL
from flask import Flask, redirect, render_template, request
from flask_mail import Mail, Message
# B@r1$k0v1$k1$
app = Flask(__name__)
app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
app.config["MAIL_PORT"] = 465
app.config["MAIL_SERVER"] = "smtp.gmail.com"
app.config["MAIL_USE_TLS"] = True

app.config["MAIL_USERNAME"] = os.getenv("MAIL_USERNAME")
mail = Mail(app)

SPORTS = [
    "Dodgeball",
    "Basketball",
    "Football",
    "Volleyball",
    "Swimming"
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():
    email = request.form.get("email")
    if not email:
        return render_template("error.html", mensage="Missing email")
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", mensage="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", mensage="Invalid sport")

    message = Message("You're registered!", recipients=[email])
    mail.send(message)

    return render_template("/sucess.html")