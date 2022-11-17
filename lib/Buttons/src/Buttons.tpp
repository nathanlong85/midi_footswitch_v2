template <class T>
std::vector<T> Button<T>::registered;

template <class T>
void Button<T>::read()
{
  for (size_t i = 0; i < registered.size(); i++)
  {
    // registered[i].handleSwitchState();
  }
}
