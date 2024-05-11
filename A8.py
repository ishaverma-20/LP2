# Define the Knowledge Base for Diseases and Their Symptoms
knowledge_base = {
    'Common Cold': {
        'Symptoms': ['runny nose', 'sneezing', 'cough'],
        'Treatment': 'Rest, fluids, over-the-counter cold medications',
        'Description': 'A viral infection affecting the nose and throat',
        'Doctor': 'Dr. Smith'
    },
    'Influenza': {
        'Symptoms': ['fever', 'body aches', 'fatigue'],
        'Treatment': 'Rest, fluids, antiviral medications (if started early)',
        'Description': 'A contagious respiratory illness caused by influenza viruses',
        'Doctor': 'Dr. Johnson'
    },
    'Pneumonia': {
        'Symptoms': ['fever', 'cough', 'shortness of breath'],
        'Treatment': 'Antibiotics, rest, oxygen therapy (if severe)',
        'Description': 'An infection that inflames the air sacs in one or both lungs',
        'Doctor': 'Dr. Brown'
    },
    # Add more diseases and their associated information
}

# Define the Knowledge Base for Doctors and Their Specialties
doctor_specialties = {
    'Dr. Smith': 'Pediatrics',
    'Dr. Johnson': 'Internal Medicine',
    'Dr. Brown': 'Cardiology',
    # Add more doctors and specialties
}

# Define the Knowledge Base for Doctor Availability
doctor_availability = {
    'Dr. Smith': ['Monday 10:00 AM', 'Wednesday 2:00 PM', 'Friday 11:00 AM'],
    'Dr. Johnson': ['Tuesday 9:00 AM', 'Thursday 3:00 PM', 'Saturday 10:00 AM'],
    'Dr. Brown': ['Monday 1:00 PM', 'Wednesday 4:00 PM', 'Friday 2:00 PM'],
    # Add more doctors and their available time slots
}

# Function to diagnose diseases
def diagnose(symptoms):
    disease_probabilities = {}
    for disease, details in knowledge_base.items():
        match_count = sum(symptom in details['Symptoms'] for symptom in symptoms)
        probability = match_count / len(details['Symptoms'])
        disease_probabilities[disease] = probability
    return disease_probabilities

# Function to schedule an appointment
def schedule_appointment(doctor_name, time_slot):
    if doctor_name in doctor_availability:
        if time_slot in doctor_availability[doctor_name]:
            print(f"Appointment scheduled with {doctor_name} at {time_slot}.")
        else:
            print(f"{doctor_name} is not available at {time_slot}. Please choose another time.")
    else:
        print("Doctor not found in the system.")

def get_disease_details(disease_name):
    if disease_name in knowledge_base:
        details = knowledge_base[disease_name]
        print(f"\nDetails of {disease_name}:")
        print("Symptoms:", ', '.join(details['Symptoms']))
        print("Description:", details['Description'])
        print("Treatment:", details['Treatment'])
        print("Recommended Doctor:", details['Doctor'])
    else:
        print("Disease not found in the system.")

# Main function
def main():
    print("Welcome to the Hospital Management System")
    print("1. Medical Diagnosis")
    print("2. Schedule Appointment")
    print("3. Get details")
    choice = input("Please select an option (1 or 2): ")
    
    if choice == '1':
        symptoms = []
        while True:
            symptom = input("Enter a symptom (or 'quit' to stop): ").lower().trim()
            if symptom == 'quit':
                break
            symptoms.append(symptom)
    
        if symptoms:
            print("You entered the following symptoms:", symptoms)
            disease_probabilities = diagnose(symptoms)
            if disease_probabilities:
                print("\nPossible diseases based on your symptoms:")
                for disease, probability in disease_probabilities.items():
                    print(f"- {disease}: Probability {probability:.2f}")
            else:
                print("No matching diseases found based on your symptoms.")
        else:
            print("No symptoms entered.")
    
    elif choice == '2':
        print("Available Doctors:")
        for doctor, specialty in doctor_specialties.items():
            print(f"{doctor} - {specialty}")
        doctor_choice = input("Enter the name of the doctor you'd like to schedule with: ")
        if doctor_choice in doctor_specialties:
            print("Available time slots for", doctor_choice)
            print(doctor_availability[doctor_choice])
            time_slot = input("Enter the preferred time slot: ")
            schedule_appointment(doctor_choice, time_slot)
        else:
            print("Doctor not found in the system.")
    
    elif choice == '3':
        disease_name = input("Enter the name of the disease: ")
        get_disease_details(disease_name)
    
    else:
        print("Invalid choice.")

if __name__ == "__main__":
    main()