import os
import re

def extract_class_definitions(file_content):
    class_definitions = []
    class_pattern = re.compile(r'class\s+\w+.*?{.*?};', re.DOTALL)
    matches = class_pattern.findall(file_content)
    for match in matches:
        class_definitions.append(match)
    return class_definitions

def process_hpp_files(directory):
    class_definitions = []
    for filename in os.listdir(directory):
        if filename.endswith('.hpp'):
            filepath = os.path.join(directory, filename)
            with open(filepath, 'r') as file:
                file_content = file.read()
                class_definitions.extend(extract_class_definitions(file_content))
    return class_definitions

def main():
    includes_folder = 'includes'
    output_file = 'one.hpp'
    class_definitions = process_hpp_files(includes_folder)
    
    with open(output_file, 'w') as file:
        for class_def in class_definitions:
            file.write(class_def + '\n\n')

if __name__ == "__main__":
    main()