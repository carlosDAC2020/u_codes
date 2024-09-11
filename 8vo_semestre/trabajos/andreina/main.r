# Cargar las librerías necesarias
library(tidyverse)
library(caret)
library(ggplot2)
library(reshape2)

# Leer los archivos CSV separados por punto y coma
df_train <- read.csv("train.csv", sep = ";")
df_test <- read.csv("test.csv")

print(str(df_train))
print(str(df_test))

# Seleccionar solo las columnas numéricas
numerical_df_train <- df_train %>% select_if(is.numeric)

# Calcular la matriz de correlación
correlation_matrix <- cor(numerical_df_train, use = "complete.obs")

# Visualizar la matriz de correlación con ggplot2
correlation_matrix_melt <- melt(correlation_matrix)
ggplot(data = correlation_matrix_melt, aes(Var1, Var2, fill = value)) +
  geom_tile() +
  scale_fill_gradient2(low = "blue", high = "red", mid = "white", 
                       midpoint = 0, limit = c(-1,1), space = "Lab", 
                       name="Correlación") +
  theme_minimal() +
  theme(axis.text.x = element_text(angle = 45, vjust = 1, 
                                   size = 12, hjust = 1)) +
  coord_fixed() +
  labs(title = "Matriz de Correlación de Variables Numéricas - df_train")

# Seleccionar las 10 variables con mejor correlación con SalePrice
correlation_with_saleprice <- abs(correlation_matrix[,"SalePrice"])
top_10_features <- names(sort(correlation_with_saleprice, decreasing = TRUE))[2:11]
print("Top 10 features with highest correlation to SalePrice:")
print(top_10_features)

# Crear un nuevo dataframe con las variables seleccionadas
X <- numerical_df_train[, top_10_features]
y <- numerical_df_train$SalePrice

# Dividir los datos en conjuntos de entrenamiento y prueba
set.seed(42)
train_indices <- createDataPartition(y, p = 0.8, list = FALSE)
X_train <- X[train_indices,]
X_test <- X[-train_indices,]
y_train <- y[train_indices]
y_test <- y[-train_indices]

# Ajustar el modelo de regresión lineal
model <- lm(y_train ~ ., data = as.data.frame(X_train))

# Realizar predicciones
y_pred <- predict(model, newdata = as.data.frame(X_test))

# Calcular métricas de evaluación
mse <- mean((y_test - y_pred)^2)
rmse <- sqrt(mse)
mae <- mean(abs(y_test - y_pred))
r2 <- summary(model)$r.squared

cat("Reporte de Métricas del Modelo:\n")
cat(sprintf("Mean Squared Error (MSE): %.2f\n", mse))
cat(sprintf("Root Mean Squared Error (RMSE): %.2f\n", rmse))
cat(sprintf("Mean Absolute Error (MAE): %.2f\n", mae))
cat(sprintf("R-squared (R²): %.2f\n", r2))

# Visualizar las predicciones vs los valores reales
ggplot(data = NULL, aes(x = y_test, y = y_pred)) +
  geom_point(alpha = 0.7) +
  labs(x = "Actual SalePrice", y = "Predicted SalePrice", 
       title = "Actual vs Predicted SalePrice") +
  theme_minimal()

