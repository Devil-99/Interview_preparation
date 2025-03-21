Souvik = {
    'name': 'Souvik Maji',
    'age': 23,
    'stream': 'CSE'
}
Soumya = {
    'name':'Soumya Maji',
    'age':28,
    'stream':'CE'
}

db={}
db['Souvik']=Souvik
db['Soumya']=Soumya

import pickle

d=pickle.dumps(db)

data=pickle.loads(d)
print(data)



import os
import re
import pdfplumber
import docx
import spacy
import pandas as pd
import tkinter as tk
from tkinter import filedialog
from fuzzywuzzy import fuzz

# Load NLP model
nlp = spacy.load("en_core_web_sm")

# Define criteria
REQUIRED_SKILLS = {"react", "node.js", "aws", "postgreSQL", "typescript", "django", "fastapi", "python"}
MIN_EXPERIENCE_YEARS = 2
EDUCATION_KEYWORDS = {"computer science", "information technology", "software engineering"}

# Extract text from PDF
def extract_text_from_pdf(pdf_path):
    text = ""
    with pdfplumber.open(pdf_path) as pdf:
        for page in pdf.pages:
            text += page.extract_text() + "\n"
    return text

# Extract text from DOCX
def extract_text_from_docx(docx_path):
    doc = docx.Document(docx_path)
    return "\n".join([para.text for para in doc.paragraphs])

# Extract years of experience using regex
def extract_experience(text):
    experience_matches = re.findall(r'(\d{1,2})\s*(?:\+?|\-)?\s*(?:years?|yrs?|y.o)', text, re.IGNORECASE)
    years = max(map(int, experience_matches), default=0)
    return years

# Match skills using fuzzy matching (handles spelling variations)
def match_skills(text):
    matched = [skill for skill in REQUIRED_SKILLS if any(fuzz.partial_ratio(skill, word) > 80 for word in text.lower().split())]
    return matched

# Check for relevant education
def check_education(text):
    return any(edu in text.lower() for edu in EDUCATION_KEYWORDS)

# Scoring function
def calculate_score(experience, matched_skills, has_education):
    skill_score = len(matched_skills) * 2  # Each skill is worth 2 points
    experience_score = 3 if experience >= MIN_EXPERIENCE_YEARS else 1 if experience > 0 else 0
    education_score = 3 if has_education else 0
    return skill_score + experience_score + education_score

# Process resumes
def process_resumes(folder_path):
    results = []
    
    for filename in os.listdir(folder_path):
        if filename.endswith(".pdf"):
            text = extract_text_from_pdf(os.path.join(folder_path, filename))
        elif filename.endswith(".docx"):
            text = extract_text_from_docx(os.path.join(folder_path, filename))
        else:
            continue  # Skip unsupported files
        
        experience = extract_experience(text)
        matched_skills = match_skills(text)
        has_education = check_education(text)
        score = calculate_score(experience, matched_skills, has_education)

        results.append({
            "filename": filename,
            "experience_years": experience,
            "skills_matched": ", ".join(matched_skills),
            "education": "Yes" if has_education else "No",
            "score": score
        })
    
    return pd.DataFrame(results)

folder_path = "V:\Interview Preperation\Python\Dummy"

df = process_resumes(folder_path)
df = df.sort_values(by="score", ascending=False)
df.to_csv("filtered_resumes.csv", index=False)
print("✅ Resume filtering complete. Results saved to filtered_resumes.csv")

