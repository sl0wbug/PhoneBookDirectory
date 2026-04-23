// PhoneBook.kt
data class Contact(val name: String, val phone: String)

class PhoneBook {
    private val contacts = mutableMapOf<String, Contact>()

    fun addContact(name: String, phone: String) {
        if (contacts.containsKey(name)) {
            println("Contact with name '$name' already exists.")
        } else {
            contacts[name] = Contact(name, phone)
            println("Contact added: $name -> $phone")
        }
    }

    fun searchContact(name: String) {
        val contact = contacts[name]
        if (contact != null) {
            println("Found: ${contact.name} -> ${contact.phone}")
        } else {
            println("No contact found with name '$name'")
        }
    }

    fun deleteContact(name: String) {
        if (contacts.remove(name) != null) {
            println("Contact '$name' deleted.")
        } else {
            println("No contact found with name '$name'")
        }
    }

    fun listContacts() {
        if (contacts.isEmpty()) {
            println("Phone book is empty.")
        } else {
            println("Contacts in Phone Book:")
            contacts.values.forEach { println("${it.name} -> ${it.phone}") }
        }
    }
}

fun main() {
    val phoneBook = PhoneBook()

    phoneBook.addContact("Alice", "123-456-7890")
    phoneBook.addContact("Bob", "987-654-3210")

    phoneBook.listContacts()

    phoneBook.searchContact("Alice")
    phoneBook.deleteContact("Bob")

    phoneBook.listContacts()
}
