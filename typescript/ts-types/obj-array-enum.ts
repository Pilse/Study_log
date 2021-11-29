const person0: {
  name: string,
  age: number
} = {
  name: 'pilse',
  age: 30
};

const person1: {
  name: string;
  age: number;
  hobbies: string[]
  role: [number, string]
} = {
  name: 'pilse',
  age: 30,
  hobbies: ['Sports', 'Cooking'],
  role: [2, 'author']
};

enum Role { ADMIN = 5, READ_ONLY, AUTHOR }

const person2 = {
  name: 'pilse',
  age: 30,
  hobbies: ['Sports', 'Cooking'],
  role: Role.ADMIN
};

let favoirteActivities: string[];
favoirteActivities = ['Sports'];

for (const hobby of person2.hobbies) {
  console.log(hobby.toUpperCase);
  // hobby.map  ==> error
}