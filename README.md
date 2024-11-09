# Hashing objects corresponding to mailing addresses
- Program reads a text file containing an extensive list of mailing addresses and hashes them into a hash table
- Hash table is a vector of size M with each slot storing another vector so as to implement separate chaining as the collision resolution method
- integers i are hashed using the formula h(i) = i % M
- strings s are hashed using the hash function (Horner's method): <br/> <img width="250" alt="Screenshot 2024-11-09 at 12 14 40 AM" src="https://github.com/user-attachments/assets/a0bc9ed3-5112-46df-8240-a813fec97992">
- the mailing addresses are a combination of strings and integers and are hashed into the hash table using the hash function: h(address) = (((((street*R+city)%M)*R+state)%M)*R+zipcode)%M

