import os

def process_cpp_files(directory):
	for filename in os.listdir(directory):
		if filename.endswith('.cpp'):
			filepath = os.path.join(directory, filename)
			with open(filepath, 'r') as file:
				lines = file.readlines()
			
			# Remove all lines containing #include
			lines = [line for line in lines if not line.strip().startswith('#include')]
			
			# Insert the new include at line 13
			lines.insert(12, '#include "../includes/one.hpp"\n')
			
			with open(filepath, 'w') as file:
				file.writelines(lines)

def main():
	src_folder = 'src'
	process_cpp_files(src_folder)

if __name__ == "__main__":
	main()