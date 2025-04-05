-- Create a table for books
CREATE TABLE Books (
    BookID INT PRIMARY KEY,
    Title VARCHAR(255) NOT NULL,
    Author VARCHAR(255) NOT NULL,
    Price DECIMAL(10, 2) NOT NULL,
    PublicationDate DATE
);


INSERT INTO Books (BookID, Title, Author, Price, PublicationDate)
VALUES
(1, 'To Kill a Mockingbird', 'Harper Lee', 15.99, '1960-07-11'),
(2, '1984', 'George Orwell', 12.99, '1949-06-08'),
(3, 'Pride and Prejudice', 'Jane Austen', 10.99, '1813-01-28');

-- Retrieve all the data\
SELECT * FROM Books;
