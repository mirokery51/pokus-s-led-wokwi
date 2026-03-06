# Ako vytvoriť nový repozitár s lokálnym aj vzdialeným prístupom

Tento sprievodca vysvetľuje, ako vytvoriť nový GitHub repozitár a nastaviť ho tak, aby ste mali lokálny prístup na viacerých zariadeniach aj vzdialený prístup cez GitHub.

---

## 1. Vytvorenie repozitára na GitHub

1. Prihláste sa na [github.com](https://github.com).
2. Kliknite na tlačidlo **„New"** (alebo na ikonu **+** vpravo hore → **New repository**).
3. Vyplňte:
   - **Repository name** – názov repozitára (napr. `moj-projekt`)
   - **Description** – voliteľný popis
   - Zvoľte **Public** (verejný) alebo **Private** (súkromný)
   - Zaškrtnite **Add a README file** (odporúčané)
4. Kliknite na **Create repository**.

---

## 2. Klonovanie repozitára na lokálne zariadenie

Na každom zariadení, kde chcete pracovať s repozitárom, ho naklonujete príkazom:

```bash
git clone https://github.com/<váš-používateľský-názov>/<názov-repozitára>.git
```

Napríklad:

```bash
git clone https://github.com/mirokery51/moj-projekt.git
```

Po klonovaní vstúpte do priečinka projektu:

```bash
cd moj-projekt
```

---

## 3. Nastavenie identity (iba raz na každom zariadení)

Pred prvým commitom nastavte svoje meno a e-mail:

```bash
git config --global user.name "Vaše Meno"
git config --global user.email "vas@email.com"
```

---

## 4. Základný pracovný postup

### Stiahnutie najnovších zmien (pred začatím práce)

```bash
git pull
```

### Uloženie zmien a odoslanie na GitHub

```bash
git add .
git commit -m "Popis zmeny"
git push
```

---

## 5. Prístup z viacerých zariadení

Ak chcete pracovať s rovnakým repozitárom na viacerých zariadeniach (napr. doma aj v škole):

1. Na každom zariadení naklonujte repozitár podľa kroku 2.
2. Pred každou prácou spustite `git pull`, aby ste mali najnovšiu verziu.
3. Po skončení práce spustite `git push`, aby ste zmeny odoslali na GitHub.

> **Tip:** Ak pracujete na viacerých zariadeniach súčasne, odporúčame používať vetvy (`git branch`) a zlúčenie (`git merge` alebo Pull Request), aby ste predišli konfliktom.

---

## 6. Overenie vzdialeného repozitára

Ak chcete skontrolovať, na aký vzdialený repozitár je váš lokálny repozitár napojený:

```bash
git remote -v
```

---

## Užitočné zdroje

- [Dokumentácia GitHub](https://docs.github.com/en/get-started)
- [Git príručka (po slovensky)](https://git-scm.com/book/sk/v2)
- [GitHub Desktop](https://desktop.github.com/) – grafický klient pre Git bez príkazového riadku
