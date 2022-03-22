from flask import Flask, render_template, request
from flask_bootstrap import Bootstrap
from logic.person import Person
from logic.document import Document

app = Flask(__name__)
bootstrap = Bootstrap(app)
peopel = []
docs= []

@app.route("/")
def index():
    return render_template('index.html')

@app.route('/people')
def people():
    data = [(i.id_person, i.name, i.last_name) for i in peopel]
    print(data)
    return render_template('people.html', value=data)

# pedir datos de personas
@app.route('/person', methods=['GET'])
def person():
    return render_template('person.html')

@app.route('/person_detail', methods=['POST'])
def person_detail():
    id_person = request.form['id_person']
    first_name = request.form['first_name']
    last_name = request.form['last_name']
    p = Person(id_person=id_person, name=first_name, last_name=last_name)
    peopel.append(p)
    return render_template('person_detail.html', value=p)




@app.route('/documents')
def documents():
    data = [(i.id_book, i.title, i.num_pages, i.category, i.authors) for i in docs]
    print(data)
    return render_template('documentos.html', value=data)

# pedir datos del documento
@app.route('/document', methods=['GET'])
def document():
    return render_template('document.html')

@app.route('/document_detail', methods=['POST'])
def document_detail():
    id_book = request.form['id_book']
    title = request.form['title']
    num_pages = request.form['num_pages']
    category = request.form['category']
    authors = request.form['authors']
    d = Document(id_book=id_book, tilte=title, num_pages=num_pages, category=category, authors=authors)
    docs.append(d)
    return render_template('document_detail.html', value=d)



if __name__ == '__main__':
    app.run(debug=True)