from flask import Flask, redirect, render_template, request, session
from flask_session import Session

app = Flask(__name__)
app.secret_key = b'u/\xa4:[jT\x9bE\xd7j`\x90*\x0b\x19\x98\xc5c\xe10'
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "file_system"
Session(app)

@app.route("/")
def index():
    if not session.get("name"):
        return redirect("/login")
    return render_template("index.html")

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
    #Remember that user logged in
        session["name"] = request.form.get("name")
    #Redirect user to /
        return redirect("/")
    return render_template("login.html")